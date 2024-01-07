#include <filesystem>
#include <mlpack.hpp>
#include <argparse/argparse.hpp>

int main(int argc, char **argv) {
  argparse::ArgumentParser program("nmf");
  program.add_description("Performs non-negative matrix factorization on the input file, outputting the W and H matrices in separate csv files.");
  program.add_argument("input")
    .help("relative path to input file");
  program.add_argument("-r", "--rank")
    .help("rank of the decomposition (equivalent to n_components in sklearn)")
    .nargs(1)
    .default_value(7)
    .scan<'i', int>();
  program.add_argument("-o", "--output")
    .nargs(1)
    .help("directory where the output matrices should be saved")
    .default_value("./");
  program.add_argument("-p", "--prepend-input")
    .help("prepend name of input file to W.csv and H.csv files (boolean flag)")
    .flag();

  try {
    program.parse_args(argc, argv);
  }
  catch (const std::exception& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    std::exit(1);
  }

  auto r = program.get<int>("-r");
  auto fname = program.get<std::string>("input");
  auto opath = program.get<std::string>("-o");

  std::string H_path = "H.csv";
  std::string W_path = "W.csv";

  arma::mat V;
  arma::mat W, H;

  if(!mlpack::data::Load(fname, V)) {
    throw std::runtime_error("could not load file");
  }

  mlpack::NMFALSFactorizer nmf;
  double residue = nmf.Apply(V, r, H, W);

  if (program["-p"] == true) {
    std::string fname_base = std::string(std::filesystem::path(fname).stem());
    H_path = fname_base + "_" + H_path;
    W_path = fname_base + "_" + W_path;
  }

  if (program.is_used("-o")) {
    mlpack::data::Save(opath + "/" + W_path, W);
    mlpack::data::Save(opath + "/" + H_path, H);
  } else {
    mlpack::data::Save(W_path, W);
    mlpack::data::Save(H_path, H);
  }

  return 0;
}
