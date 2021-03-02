import 'dart:io';
import 'dart:math';
main (List<String> ARGS){
	print(candiesDistribute(ARGS,ARGS.length));	
}
int candiesDistribute(List<String> candyType, int n){
	Set candies = new Set.from(candyType);
	return min((n/2).toInt(),candies.length);
}

