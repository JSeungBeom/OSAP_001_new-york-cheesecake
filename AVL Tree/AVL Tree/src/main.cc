/*
Copyright (C)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>

2023 by Seungbeom Jang <wkdtmf357@gmail.com>

*/

#include "avl_tree_set.cc"
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int T, Q;

  std::cin >> T;

  std::string func;
  int x;

  while (T--) {
    std::cin >> Q;
    AVLTreeSet<int> set;
    while (Q--) {
      std::cin >> func;

      if (func == "minimum") {
        std::cin >> x;
        std::cout << set.Minimum(x) << '\n';
      } else if (func == "maximum") {
        std::cin >> x;
        std::cout << set.Maximum(x) << '\n';
      } else if (func == "empty") {
        std::cout << set.Empty() << '\n';
      } else if (func == "size") {
        std::cout << set.Size() << '\n';
      } else if (func == "find") {
        std::cin >> x;
        std::cout << set.Find(x) << '\n';
      } else if (func == "insert") {
        std::cin >> x;
        std::cout << set.Insert(x) << '\n';
      } else if (func == "rank") {
        std::cin >> x;
        std::cout << set.Rank(x) << '\n';
      } else if (func == "erase") {
        std::cin >> x;
        std::cout << set.Erase(x) << '\n';
      }
    }
  }
}