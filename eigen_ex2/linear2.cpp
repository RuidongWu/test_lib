
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

#include <Eigen/Dense>

using namespace std;

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cout << "Usage : ./linear dim" << endl;
    return EXIT_FAILURE;
  }

  chrono::time_point<chrono::system_clock> start, end;
  chrono::duration<double> elapsed_seconds;
  time_t end_time;
  cout << "Number of threads used by Eigen: " << Eigen::nbThreads() << endl;

  start = chrono::system_clock::now();
  int dim = atoi(argv[1]);
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(dim, dim);
  Eigen::MatrixXd B = Eigen::VectorXd::Random(dim);
  end = chrono::system_clock::now();

  elapsed_seconds = end - start;
  end_time = chrono::system_clock::to_time_t(end);
  cout << "Matrix allocated and initialized "
       << put_time(localtime(&end_time), "%a %b %d %Y %r\n")
       << "elapsed time: " << elapsed_seconds.count() << "s\n";

  start = chrono::system_clock::now();

  Eigen::MatrixXd A1 = A;
  Eigen::VectorXd B1 = B;
  end = chrono::system_clock::now();
  end_time = chrono::system_clock::to_time_t(end);
  cout << "Scaling done, A and B saved "
       << put_time(localtime(&end_time), "%a %b %d %Y %r\n")
       << "elapsed time: " << elapsed_seconds.count() << "s\n";
  start = chrono::system_clock::now();
  Eigen::VectorXd x = A.lu().solve(B);
  end = chrono::system_clock::now();

  elapsed_seconds = end - start;
  end_time = chrono::system_clock::to_time_t(end);
  double relative_error = (A * x - B).norm() / B.norm();
  cout << "Linear system solver done "
       << put_time(localtime(&end_time), "%a %b %d %Y %r\n")
       << "elasped time: " << elapsed_seconds.count() << "s\n";

  cout << "relative error is " << relative_error << endl;

  return 0;
}