要項
====
NixysaでGoogle Chrome用のサンプルプラグインを作ってみた
四則演算を行うプラグイン

対象環境
========
- Nixysa (NPAPIのラップライブラリ)
- Subversion or TortoiseSVN (Nixysaのコード取得用)
- git
- Python (Nixysaを動作させるため)
- Visual C++ 2010 (プラグインのビルド)
- Google Chrome 9

ビルド方法
==========
コマンドプロンプトでの作業
    >svn checkout http://nixysa.googlecode.com/svn/trunk/ nixysa-read-only
    >cd nixysa-read-only
    >git clone git://github.com/nus/NPAPISample.git
    >start NPAPISample\calculator.sln
    
Visual C++での作業
1.メニューバー -> ビルド -> 構成マネージャー
アクティブソリューション構成の[Debug]から[Release]に変更
2.メニューバー -> ビルド -> calculatorのビルド

もし、下記の様なビルドエラーが起きたら
    1>C:\Program Files\Microsoft SDKs\Windows\v7.0A\include\winnt.h(6361): error C2146: 構文エラー : ';' が、識別子 'ContextRecord' の前に必要です。
    1>C:\Program Files\Microsoft SDKs\Windows\v7.0A\include\winnt.h(6361): error C4430: 型指定子がありません - int と仮定しました。メモ: C++ は int を既定値としてサポートしていません
    1>C:\Program Files\Microsoft SDKs\Windows\v7.0A\include\winnt.h(6361): error C4430: 型指定子がありません - int と仮定しました。メモ: C++ は int を既定値としてサポートしていません
    1>C:\Program Files\Microsoft SDKs\Windows\v7.0A\include\winnt.h(12983): error C2065: 'PCONTEXT' : 定義されていない識別子です。
    1>C:\Program Files\Microsoft SDKs\Windows\v7.0A\include\winnt.h(12984): error C2146: 構文エラー : ')' が、識別子 'ContextRecord' の前に必要です。
    1>C:\Program Files\Microsoft SDKs\Windows\v7.0A\include\winnt.h(12984): warning C4229: 旧形式が使用されています : データの修飾子は無視されます。
    1>C:\Program Files\Microsoft SDKs\Windows\v7.0A\include\winnt.h(12984): error C2182: 'RtlCaptureContext' : 'void' 型が不適切に使用されています。
    1>C:\Program Files\Microsoft SDKs\Windows\v7.0A\include\winnt.h(12984): error C2491: 'RtlCaptureContext' : dllimport データ の定義は許されません。
    1>C:\Program Files\Microsoft SDKs\Windows\v7.0A\include\winnt.h(12984): error C2059: 構文エラー : ')'
   以下同様なエラー
   ...

nixysa-read-only\third_party\npapi\include\nptypes.hの48行目に1行追加
    47|#if defined(WIN32) || defined(OS2)
    48|    #include <Windows.h>	// この行を追加

nixysa-read-only\nixysa\static_glue\npapi\npn_api.hの107,108行目の
    107| size_t size = std::min(sizeof(g_browser_functions),
    108|                        static_cast<size_t>(funcs->size));
を
    107| size_t size;
    108| {
    109|     using namespace std;
    110|    size = min(sizeof(g_browser_functions),
    111|                      static_cast<size_t>(funcs->size));
    112| };
に変更


