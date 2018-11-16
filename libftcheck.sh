#!/bin/sh

printf "\e[42m\e[30m  Automated tester by efouille X afrangio  \e[39m\e[49m\n"

printf "\e[32mCreating /tmp/eft working directory\e[39m\n"
rm -rf /tmp/eft
mkdir -p /tmp/eft
cd /tmp/eft

printf "\e[32m----------\nCloning libft into /tmp/eft/libft\e[39m\n"
git clone $1 libft

printf "\e[32m----------\nDownloading clang static analyzer into /tmp/eft/static_analyzer\e[39m\n"
curl -o checker-279.tar.bz2 https://clang-analyzer.llvm.org/downloads/checker-279.tar.bz2
printf "\e[32m----------\nExtracting clang static analyzer...\e[39m\n"
tar jxf checker-279.tar.bz2
rm -rf checker-279.tar.bz2
mv checker-279 static_analyzer
printf "\e[32m----------\nChecking with scan-build...\e[39m\n"
static_analyzer/bin/scan-build make -C libft
make -C libft fclean

printf "\e[32mDone.\e[39m\nPress enter to continue"
read

printf "\e[32m----------\nCloning 42FileChecker by jgigault into /tmp/eft/42fc...\e[39m\n"
git clone https://github.com/jgigault/42FileChecker 42fc
printf "\e[32m----------\nCloning libftest by jtoty (efouille fork) into /tmp/eft/libftest...\e[39m\n"
git clone https://github.com/edrflt/Libftest.git libftest

printf "\e[32m----------\nChecking with 42FileChecker...\e[39m\n"
cd 42fc
sh 42FileChecker.sh --project "libft" --path "/tmp/eft/libft"

printf "\e[32mEnd of 42fc\e[39m\nPress enter to continue"
read

printf "\e[32m----------\nChecking with libftest...\e[39m\n"
cd ../libftest
sh grademe.sh

printf "\e[32mEnd of libftest\e[39m\nPress enter to continue"
read

voidcast=$(grep --color -nr "(void)" /tmp/eft/libft | wc | awk {'print $1'})
if [ $voidcast -gt 0 ]
then
	printf "\e[31m(void) FOUND HERE :\e[39m\n"
	grep --color -nr "(void)" /tmp/eft/libft
else
	printf "\e[32mNo (void) casts found\e[39m\n"
fi