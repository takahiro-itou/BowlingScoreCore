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
**      サンプルプログラム。
**
**      @file       Bin/SampleApplication.cpp
**/

#include    "BowlingScore/Common/DocumentFile.h"
#include    "BowlingScore/Common/ScoreDocument.h"

#include    <iostream>

using   namespace   BOWLINGSCORE_NAMESPACE;

int  main(int argc, char * argv[])
{
    Common::DocumentFile    docFile;
    Common::ScoreDocument   objDoc;
    ErrCode                 retCode;

    if ( argc <= 1 ) {
        return ( 2 );
    }

    retCode = docFile.readFromTextFile(
                    argv[1],
                    &objDoc);
    if ( retCode != ErrCode::SUCCESS ) {
        return ( static_cast<int>(retCode) );
    }

    return ( 0 );
}
