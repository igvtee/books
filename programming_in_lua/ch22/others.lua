print(os.getenv("HOME"))

function createDir (dirname)
	os.execute("mkdir " .. dirname)
end

print(os.setlocale("ISO-8859-1", "collate")) --> ISO-8859-1
