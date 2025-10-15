=== 調用gdb ===
gdb program
gdb program core
gdb program pid
gdb -args program args
=== 選擇文件 ===
-s file	:從檔案讀入符號表
-e file :執行檔案
-se file :執行檔案並讀入符號表
-c file :載入core dump檔案
-p pid :debug pid的程式
-x file :從檔案執行gdb命令
-d directory :加入路徑作為source/script的搜索路徑
=== 選擇模式 ===
-q :安靜模式
-batch :批次處理模式
-return-child-result :子進程的回傳值
-cd directory :改用設定的目錄為工作目錄
-b bps :設定串口速度
-l timeout :遠端調試時的timeout
-t device :將設備作為你程式的標準輸入輸出
-tui :支援多視窗,可顯示code,assemble,register
-interpreter interp : 把解釋器作為控制程序或設備的接口
-statistics :顯示時間和內存統計資訊
-version :版本
=== tui ===
ctrl + x + a :切換tui
ctrl + L :刷新畫面
ctrl + x + 2 :組合語言. 再按一次出現register內容
ctrl + p / ctrl + n :歷史指令
ctrl + x + o :切換active window
=== python ===
python :gdb 內建python
(gdb) python
>import os
>print('current pid %d' % os.getpid())
>end
current pid 46238
(gdb) python gdb.Breakpoint('7')
(gdb) python bp = gdb.Breakpoint('10')
(gdb) python bp.enabled = False
(gdb) python print (gdb.breakpoints())
(gdb) python print (gdb.breakpoints()[0].location)
(gdb) python print (gdb.breakpoints()[0].enabled)
(gdb) python python_var = gdb.parse_and_eval('code_var_name')
(gdb) python gdb.execute('next')
(gdb) python help('gdb')
=== reverse debugging ===
ulimit -c unlimited
while ./bubble_sort; do echo OK; done
unzstd /var/lib/systemd/coredump/core.bubble_sort.*.zst
(gdb) start
(gdb) b main
(gdb) b _exit
(gdb) info b
(gdb) command 2
(gdb) record
(gdb) continue
(gdb) end
(gdb) set pagination off
(gdb) command 3
(gdb) run
(gdb) end
(gdb) run
(gdb) reverse-stepi
(gdb) disassemble
(gdb) print $sp     (ex. 0x7fffffffda38)
(gdb) print *(long**)0x7fffffffda38 (ex. 0x66a9171d)
(gdb) x $4
(gdb) watch *(long**)0x7fffffffda38
(gdb) reverse-continue
=== .gdbinit ===
set history save on
set print pretty on
set pagination on
set confirm off
=== fork ===
set follow-fork-mode child|parent
set detach-on-fork off
info inferiors
inferior [infno]
set follow-exec-mode new|same
add inferior [name]
clone-inferior
=== threads ===
thread apply 1-4 print $sp
thread apply all backtrace
thread apply all backtrace full
=== misc ===
(gdb) info line hello.c:6
(gdb) info line *$pc
(gdb) save breakpoints breakpoints.record
(gdb) dprintf location,template,expression [,expression ...]

