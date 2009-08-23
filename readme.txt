========================================================================

VibraMouse - mouse cursor vibration tool

Copyright (C) 2009 aike. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

History:
2009-08-23
  First version.
========================================================================

■これは何？
マウスカーソルを自動的に動かしてサインカーブを書くツールです。
VOCALOIDのビブラートを手書きする目的で作りました。

■インストール
インストールは特に必要ありません。任意のフォルダにvibramouse.exeとvibramouselib.dll
を置いて実行するだけです。Windowsフォルダに自動的にvibramouse.iniが作成されます。

レジストリは使用しません。アンインストールは、vibramouse.exeとvibramouselib.dll、
Windowsフォルダのvibramouse.iniを削除してください。

■操作方法
デフォルトでは、ALT + Z キーを押すとマウスが揺れながら右側に移動します。
タイミングを合わせて左クリックするとサインカーブが描画できると思います。

■パラメータ説明
操作してみるとすぐ理解できると思いますが、それぞれのパラメータは次の意味を持ちます。
　長さ　水平方向の距離です
　周期　振動する周期です
　振幅　垂直方向に振動する幅です
　増幅　徐々に振幅を増加するようになります
　上下　振動の中心を傾けます。
　下降　振動の中心を指数関数的に下げます。

■カスタマイズ
sample_vibramouse.iniを参考にして、vibramouse.iniに以下のパラメータを追加すると
カスタマイズができます。

キーアサインのパラメータです。ModifireにはALT/SHIFT/CTRLが指定できます。
アプリケーションですでに使用されているショートカットキーと重ならないように
してください。
　[Config]
　Key=Z
　Modifire=ALT

マウスカーソルを移動させる速度を指定します。デフォルトは20です。
　[Config]
　Speed=20

■開発環境
Windows XP
Visual C++ 2008 Express Edition

========================================================================
