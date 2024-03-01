## 実習環境　＜リアルタイムOS＞  
＜開発マシン＞  
メインPC : windows10  
統合開発環境 : Eclipse + TOPPERS/ASP ソースコード(Armadillo460用)  
コンパイラ : GNU C Compiler(GCC)ARM用 + GNU Make   
デバッグ : OpenOCD、アルファプロジェクト社:HJ-LINK/usb  
ターミナル : TeraTerm  
  
<ターゲットボード>  
実習ボード : アットマークテクノ製「Armadillo-460」  

## 動作
10台止められる駐車場の入出場をセマフォによって管理  
TeraTermに結果が表示  
<実行結果例>  
Main-->実行開始  
Main-->タスクの起動  
Main-->自タスクの終了  
Task_Car_In Start  
Task_Car_Out Start  
Task_Park_In Start  
Task_Park_Out Start  
車が来ました。  
Task_Park_In-->セマフォの獲得  
Task_Park_In-->セマフォの獲得成功  
車が入場しました。(待ち 0 台 空き 9 台)  
車が来ました。  
Task_Park_In-->セマフォの獲得  
Task_Park_In-->セマフォの獲得成功  
車が入場しました。(待ち 0 台 空き 8 台)  
車が来ました。  
Task_Park_In-->セマフォの獲得  
Task_Park_In-->セマフォの獲得成功  
車が入場しました。(待ち 0 台 空き 7 台)  
車が出ます。  
Task_Park_Out-->セマフォの返却  
車が出場しました。(待ち 0 台 空き 8 台)  
...
車が来ました。  
車が来ました。  
車が来ました。  
車が出ます。  
Task_Park_Out-->セマフォの返却  
車が出場しました。(待ち 4 台 空き 1 台)  
Task_Park_In-->セマフォの獲得成功  
車が入場しました。(待ち 3 台 空き 0 台)  
...
