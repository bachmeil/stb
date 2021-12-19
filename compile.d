import std.algorithm.sorting, std.array, std.file, std.path, std.process, std.stdio, std.string;

void main() {
	auto files = std.file.dirEntries(".", "*.h", SpanMode.shallow);
	foreach(_f; files) {
		auto f = stripExtension(baseName(_f));
		string cmd = `gcc -E -P ` ~ f ~ `.h > ` ~ f ~ `_tmp.c`;
		writeln(cmd);
		writeln(executeShell(cmd).output);
		cmd = `gcc -E -P -include fixes.c ` ~ f ~ `_tmp.c > ` ~ f ~ `.c`;
		writeln(cmd);
		writeln(executeShell(cmd).output);
		remove(f ~ "_tmp.c");
		cmd = `ldmd2 -c ` ~ f ~ `.c`;
		writeln(cmd);
		writeln(executeShell(cmd).output);
    copy(f ~ ".c", "unmodified/" ~ f ~ ".c");
    remove(f ~ ".c");
    if (exists(f ~ ".o")) { remove(f ~ ".o"); }
	}
}
