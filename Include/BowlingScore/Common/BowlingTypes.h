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
**      プロジェクトの設定。
**
**      @file       Common/BowlingTypes.h
**/

#if !defined( BOWLINGSCORE_COMMON_INCLUDED_BOWLING_TYPES_H )
#    define   BOWLINGSCORE_COMMON_INCLUDED_BOWLING_TYPES_H

#if !defined( BOWLINGSCORE_COMMON_INCLUDED_BOWLING_SETTINGS_H )
#    include    "BowlingSettings.h"
#endif

#if !defined( BOWLINGSCORE_SYS_INCLUDED_CSTDINT )
#    include    <cstdint>
#    define   BOWLINGSCORE_SYS_INCLUDED_CSTDINT
#endif


BOWLINGSCORE_NAMESPACE_BEGIN

//========================================================================
//
//    Type Definitions.
//

//----------------------------------------------------------------
/**
**    エラーコード。
**/

enum class  ErrCode
{
    /**   正常終了。    **/
    SUCCESS                 = 0,

    /**   異常終了。エラーの理由は不明または報告なし。  **/
    FAILURE                 = 1,

    /**   無効なインデックス指定。  **/
    INDEX_OUT_OF_RANGE      = 2,

    /**   ファイルオープンエラー。  **/
    FILE_OPEN_ERROR         = 3,

    /**   ファイル入出力エラー。    **/
    FILE_IO_ERROR           = 4,

    /**   不正なファイル形式。      **/
    FILE_INVALID_FORMAT     = 5,
};

//----------------------------------------------------------------
/**
**    型安全なブール型。
**/

enum  Boolean
{
    BOOL_FALSE  =  0,       /**<  偽。  **/
    BOOL_TRUE   =  1        /**<  真。  **/
};


//========================================================================
//
//    安全なポインタ型のキャスト。
//

template  <typename  T>
T  pointer_cast(void  *  p)
{
    return ( static_cast<T>(p) );
}

template  <typename  T>
T  pointer_cast(const  void  *  p)
{
    return ( static_cast<T>(p) );
}


BOWLINGSCORE_NAMESPACE_END

#endif
