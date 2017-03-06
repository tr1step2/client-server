@echo off

set BOOST_INC=C:\Users\void\develop\boost_1_63_0\
set BOOST_LIB=C:\Users\void\develop\boost_1_63_0\stage64\lib
set PLATF="x64"
set CONF=Release

msbuild FXTM-client-server.sln /p:BOOST_INC_PATH=%BOOST_INC% /p:BOOST_LIB_PATH=%BOOST_LIB% /p:Configuration=%CONF% /p:Platform=%PLATF%