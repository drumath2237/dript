# driptレンダラー

現在情報特別演習にて制作中のパストレーサである。人生初のレンダラー開発。名前は「dript」で「滴る」の過去形だが、パストレーサの、名前の最後に「～pt」とつける慣習に由来する。今回の情報特別演習ではやらないが、いずれはGPU対応のフォトンマッピングレンダラーを開発したいと思っている。

## 実装したい機能

- .objファイルの読み込み
- パストレーシング
- ポリゴンメッシュ対応
- GUI

## Usage

```bash
clang app.cpp -o app.exe -std=c++17
./app
./result.ppm
```

作者の環境では、```clang 6.0.0```を使っていますが、```c++17```でコンパイルできる環境なら大丈夫なはずです。以下、テスト済み環境。

- Windows 10
- clang 6.0.0
- CPU core-i7 7700

## 進捗

- 7/28　交差判定ができた。
- 7/29 法線マップ表示ができた。