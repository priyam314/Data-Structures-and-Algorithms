import std.stdio;
import std.algorithm.mutation;
import std.array;

void main(string[] ARGS){
	writeln(join(ARGS[1 .. $].dup.reverse," "));
}
