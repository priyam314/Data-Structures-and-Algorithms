main(List<String> args){
	for (String arg in args){
		print(reversed(arg));
	}
}
String reversed(String s){
	return s.split('').reversed.join('');
	
}

String reverse0(String s) {
  return s.split('').reversed.join('');
}

String reverse1(String s) {
  var sb = new StringBuffer();
  for(var i = s.length - 1; i >= 0; --i) {
    sb.write(s[i]);
  }
  return sb.toString();
}

String reverse2(String s) {
  return new String.fromCharCodes(s.codeUnits.reversed);
}

String reverse3(String s) {
  var sb = new StringBuffer();
  for(var i = s.length - 1; i >= 0; --i) {
    sb.writeCharCode(s.codeUnitAt(i));
  }
  return sb.toString();
}

String reverse4(String s) {
  var sb = new StringBuffer();

  var i = s.length - 1;

  while (i >= 3) {
    sb.writeCharCode(s.codeUnitAt(i-0));
    sb.writeCharCode(s.codeUnitAt(i-1));
    sb.writeCharCode(s.codeUnitAt(i-2));
    sb.writeCharCode(s.codeUnitAt(i-3));
    i -= 4;
  }

  while (i >= 0) {
    sb.writeCharCode(s.codeUnitAt(i));
    i -= 1;
  }

  return sb.toString();
}

String reverse5(String s) {
  var length = s.length;
  var charCodes = new List(length);
  for(var index = 0; index < length; index++) {
    charCodes[index] = s.codeUnitAt(length - index - 1);
  }

  return new String.fromCharCodes(charCodes);
}
main() {
  var s = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.";

  time('reverse0', () => reverse0(s));
  time('reverse1', () => reverse1(s));
  time('reverse2', () => reverse2(s));
  time('reverse3', () => reverse3(s));
  time('reverse4', () => reverse4(s));
  time('reverse5', () => reverse5(s));
}
