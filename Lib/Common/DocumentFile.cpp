//  -*-  coding: utf-8-with-signature;  mode: c++  -*-  //
/*************************************************************************
**                                                                      **
**                      ---   Bowling Score.   ---                      **
**                                                                      **
**          Copyright (C), 2025-2025, Takahiro Itou                     **
**          All Rights Reserved.                                        **
**                                                                      **
**          License: (See COPYING or LICENSE files)                     **
**          GNU Affero General Public License (AGPL) version 3,         **
**          or (at your option) any later version.                      **
**                                                                      **
*************************************************************************/

/**
**      An Implementation of DocumentFile class.
**
**      @file       Common/DocumentFile.cpp
**/

#include    "BowlingScore/Common/DocumentFile.h"

#include    "BowlingScore/Common/ScoreDocument.h"

#include    <fstream>
#include    <sstream>


BOWLINGSCORE_NAMESPACE_BEGIN
namespace  Common  {

namespace  {

}   //  End of (Unnamed) namespace.


//========================================================================
//
//    DocumentFile  class.
//

//========================================================================
//
//    Constructor(s) and Destructor.
//

//----------------------------------------------------------------
//    インスタンスを初期化する
//  （デフォルトコンストラクタ）。

DocumentFile::DocumentFile()
{
}

//----------------------------------------------------------------
//    インスタンスを破棄する
//  （デストラクタ）。
//

DocumentFile::~DocumentFile()
{
}

//========================================================================
//
//    Public Member Functions (Implement Pure Virtual).
//

//========================================================================
//
//    Public Member Functions (Overrides).
//

//========================================================================
//
//    Public Member Functions (Pure Virtual Functions).
//

//========================================================================
//
//    Public Member Functions (Virtual Functions).
//

//========================================================================
//
//    Public Member Functions.
//

//----------------------------------------------------------------
//    データをテキストファイルから読み込む。
//

ErrCode
DocumentFile::readFromTextFile(
        const  std::string  &fileName,
        ScoreDocument  *    ptrDoc)
{
    std::ifstream   ifs(fileName.c_str());
    return  readFromTextStream(ifs, ptrDoc);
}

//----------------------------------------------------------------
//    データをテキストストリームから読み込む。
//

ErrCode
DocumentFile::readFromTextStream(
        std::istream       &inStr,
        ScoreDocument  *    ptrDoc)
{
    return ( ErrCode::SUCCESS );
}

//----------------------------------------------------------------
//    データをテキストファイルに書き込む。
//

ErrCode
DocumentFile::saveToTextFile(
        const  ScoreDocument   & objDoc,
        const  std::string     & fileName)
{
    std::ofstream   ofs(fileName.c_str());
    return  saveToTextStream(objDoc, ofs);
}

//----------------------------------------------------------------
//    データをテキストストリームに書き込む。
//

ErrCode
DocumentFile::saveToTextStream(
        const  ScoreDocument   & objDoc,
        std::ostream           & outStr)
{
    outStr  <<  "# info\n"
            <<  "\ndate |"      <<  objDoc.getGameDate()
            <<  "\ntitle |"     <<  objDoc.getGameTitle()
            <<  "\nplayers |"   <<  objDoc.getNumPlayers();
    for ( PlayerIndex i = 0; i < objDoc.getNumPlayers(); ++ i ) {
        outStr  <<  "\nplayer"  <<  i
                <<  " |"
                <<  objDoc.getPlayerName(i);
    }

    outStr  <<  "\n\n# score\n\n";
    for ( PlayerIndex i = 0; i < objDoc.getNumPlayers(); ++ i ) {
        for ( FrameNumber j = 0; j < 9; ++ j ) {
            outStr  <<  i  <<  ","  <<  (j + 1)  << ", |";
            const   FrameScore  &fs = objDoc.getFrameScore(i, j);
            if ( fs.got1st == 10 ) {
                outStr  <<  "str,, |* |* |";
            } else {
                std::stringstream   rm1;
                std::stringstream   rm2;

                for ( int k = 1; k <= 10; ++ k  ) {
                    if ( (fs.rem1st >> k) & 1 ) {
                        rm1 << k << ",";
                    }
                }
                for ( int k = 1; k <= 10; ++ k  ) {
                    if ( (fs.rem2nd >> k) & 1 ) {
                        rm2 << k << ",";
                    }
                }

                outStr  <<  fs.got1st  << ",";
                if ( fs.got1st + fs.got2nd == 10 ) {
                    outStr  <<  "sp, |"
                            <<  rm1.str()
                            <<  " |"
                            <<  "* |";
                } else {
                    outStr  <<  fs.got2nd << ", |"
                            <<  rm1.str()
                            <<  " |"
                            <<  rm2.str()
                            <<  " |";
                }
            }
            outStr  <<  fs.score    <<  "\n";
        }
    }

    return ( ErrCode::SUCCESS );
}

//========================================================================
//
//    Accessors.
//

//========================================================================
//
//    Protected Member Functions.
//

//========================================================================
//
//    For Internal Use Only.
//

}   //  End of namespace  Common
BOWLINGSCORE_NAMESPACE_END
