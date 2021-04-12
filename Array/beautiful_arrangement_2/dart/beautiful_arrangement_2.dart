import 'dart:io';

// command line input
// n k
main(List<String> ARGS) {
  print(arrangements(int.parse(ARGS[0]), int.parse(ARGS[1])));
}

List<int> arrangements(int n, int k) {
  if (k >= n) {
    return [];
  }
  var temp = List<int>.filled(n, 0);
  for (int i = 0; i < n; i++) {
    temp[i] = i + 1;
  }
  var tempSlice = List<int>.filled(0, 0, growable: true);
  for (int i = 0; i < k / 2 + 1; i++) {
    if (temp[i] == temp[k - i]) {
      tempSlice.add(temp[i]);
    }
    tempSlice.add(temp[i]);
    tempSlice.add(temp[k - i]);
  }
  for (int i = 0; i < k + 1; i++) {
    temp[i] = tempSlice[i];
  }
  return temp;
}
