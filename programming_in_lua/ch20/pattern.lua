--[[
. all characters
%a letters
%c control characters
%d digits
%l lower-case letters
%p punctuation characters
%s space characters
%u upper-case letters
%w alphanumeric characters
%x hexadecimal digits
%z the character whose representation is 0
An upper-case version of any of these classes represents the complement of the class.
%b %bxy pattern from x to y. ex. "%b()", "%b[]", "%b{}", or "%b<>"

magic characters
( ) . % + - * ? [ ] ^ $
% escape for these magic characters
[] char-set, ^ complement of any char-set. ex. "[^0-7]", "%S" == "[^%s]"
+ 1 or more repetitions
* 0 or more repetitions
- also 0 or more repetitions
? optional (0 or 1 occurrence)
^ begin
$ end
() captures, use %d for previes match patter
]]--

s = "Deadline is 30/05/1999, firm"
date = "%d%d/%d%d/%d%d%d%d"
print(string.sub(s, string.find(s, date))) --> 30/05/1999

print(string.gsub("hello, up-down!", "%A", ".")) --> hello..up.down. 4
print(string.find("(55)", "%(%d+%)")) --> 1 4

text = "this is a text data"
print(string.gsub(text, "[AEIOUaeiou]", ""))

print(string.gsub("one, and two; and three", "%a+", "word")) --> word, word word; word word
print(string.find("the number 1298 is even", "%d+")) --> 12 15

test = "int x; /* x */ int y; /* y */"
print(string.gsub(test, "/%*.*%*/", "<COMMENT>")) --> int x; <COMMENT>
print(string.gsub(test, "/%*.-%*/", "<COMMENT>")) --> int x; <COMMENT> int y; <COMMENT>

test = "-12 34"
print(string.gsub(test, "[+-]?%d+", "number")) --> number number

print(string.gsub("a (enclosed (in) parentheses) line", "%b()", "")) --> a line
