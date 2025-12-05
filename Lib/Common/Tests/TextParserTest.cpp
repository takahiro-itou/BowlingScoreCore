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
**      An Implementation of Test Case 'TextParser'.
**
**      @file       Common/Tests/TextParserTest.cpp
**/

#include    "TestDriver.h"
#include    "BowlingScore/Common/TextParser.h"


BOWLINGSCORE_NAMESPACE_BEGIN
namespace  Common  {

//========================================================================
//
//    TextParserTest  class.
//
/**
**    クラス TextParser の単体テスト。
**/

class  TextParserTest : public  TestFixture
{
    CPPUNIT_TEST_SUITE(TextParserTest);
    CPPUNIT_TEST(testCtor);
    CPPUNIT_TEST_SUITE_END();

public:
    virtual  void   setUp()     override    { }
    virtual  void   tearDown()  override    { }

private:
    void  testCtor();

    typedef     TextParser      Testee;
};

CPPUNIT_TEST_SUITE_REGISTRATION( TextParserTest );

//========================================================================
//
//    Tests.
//

void  TextParserTest::testCtor()
{
    Testee  testee;

    return;
}

}   //  End of namespace  Common
BOWLINGSCORE_NAMESPACE_END

//========================================================================
//
//    エントリポイント。
//

int  main(int argc, char * argv[])
{
    return ( executeCppUnitTests(argc, argv) );
}
