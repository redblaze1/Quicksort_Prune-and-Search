# Quicksort_Prune-and-Search
作業三

### 心路歷程:
- **這個作業我交了2次,所以有3次的PDF**
- **下載PDF:[請點我](https://drive.google.com/file/d/1pFXEG9Zf-pew6ZaNYXb1wFI3qhrubf-H/view?usp=sharing)**
### 環境
- 4.15.0-65-generic x86_64 GNU/Linux
- gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
### Files Description:
| File name | Description |
| --------- | ----------- |
| `homework2.c`  | 主要的作業內容,作業所要求的內容都有達到,在第一個commit為錯誤的code,有overflow發生|
| `test.c`    | 測試homework2.c的func有沒有正常運作用的code,第一個commit同上 |
| `test2.c`  | 把網路上別人的code拿來改,第一個[commit](https://github.com/redblaze1/Quicksort_Prune-and-Search/commit/1d8b025f0d6e51b36811374ccb5d08114cc837c8#diff-054a537f807fed494884560f8073369a)為第一次PDF的內容,有quicksort,但沒有Prune-and-Search,第二次[commit](https://github.com/redblaze1/Quicksort_Prune-and-Search/commit/323696aca5d9ce96eafea41087c42e19515dc7d6#diff-054a537f807fed494884560f8073369a)為加上Prune and Search後的code |

### 本程式所參考的gif
![image](https://blog.techbridge.cc/img/huli/sorting/quick.gif)
### 本程式流程圖
![image](https://i.imgur.com/qrcIgqc.jpg)

### 效能比較:
#### 注意,code都是產生1000萬個亂數,然後尋找第500萬個大的數

#### **時間比較:**
| Code | Time |
| ---- | ---- |
| `我的code`  | 大約0.2秒|
| `別人的code`    | 大約2.2秒 |
###### 圖示:
![image](https://imgur.com/GSb0s0x.jpg)
#### **關鍵指令的執行次數比較:**
![image](https://imgur.com/IFvVJlj.jpg)
##### 
此[Shell Script File](https://github.com/redblaze1/Quicksort_Prune-and-Search/blob/master/performance/test.sh)
