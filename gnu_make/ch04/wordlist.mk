# $(wordlist start,end,text)
# $(call uid_gid, user-name)
uid_gid = $(wordlist 3, 4, \
	$(subst :, , \
	$(shell grep "^$1:" /etc/passwd)))

all:
	# root uid gid: $(call uid_gid,root)
