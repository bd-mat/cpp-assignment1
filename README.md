This repository exists to hold my program for assignment 1.

The program should do the following:
- Input an atomic number, Z
  - This should be a positive integer.
- Input initial and final quantum numbers, n_i, n_f
  - These should be positive integers.
  - They should satisfy n_i > n_f
- Calulate the required photon energy for the transition (in eV) as:
    E = 13.6 * Z^2 * (1/n_f^2 - 1/n_i^2)
- Query whether the results should be returned in eV or J
- Query to repeat the program.

Additionally, there should be input validation.
