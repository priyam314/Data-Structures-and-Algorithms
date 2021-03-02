import std.stdio;
import std.algorithm;
import std.conv;
int distributeCandies(string[] candleType,int n){
	int[string] candies;
	candleType.each!(v => candies[v]++);
	return min(n/2,candies.length);
}
void main(string[] args){
	writeln(distributeCandies(args[1 .. $],to!int(args.length)-1));
}

