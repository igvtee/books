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
