print(os.getenv("HOME"))

function createDir(dirname)
	os.execute("mkdir " .. dirname)
end

createDir("test")
os.remove("test")

os.exit(0)
