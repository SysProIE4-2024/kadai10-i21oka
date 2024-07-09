/*
 *  mysystem.c : system 関数のクローン
 */

#include <stdio.h>
#include <stdlib.h>    // exit, system のため
#include <unistd.h>    // fork, execXX のため
#include <sys/wait.h>  // wait のため
#include "mysystem.h"  // インタフェース
char *execpath ="/bin/sh";
// system関数のクローン
int mysystem(char *command) {
  int status =0;
  int pid = 0;
  if(command==NULL){
    return 1;
  }
  if((pid=fork())<0){
    return -1;
  }
  if(pid!=0){
    while (wait(&status)!=pid);
  

  }else{
    execl(execpath,"sh", "-c" ,command ,NULL);
    perror(execpath);
    exit(127);
  }

  // ここにプログラムを書く

  return status;
}

/* 実行例

ここに実行例を書く
okasakuya@okasakinarinoMacBook-Air kadai10-i21oka % ls -l
total 616
-rw-r--r--  1 okasakuya  staff     143  7  9 21:29 Makefile
-rw-r--r--  1 okasakuya  staff    2795  7  9 21:29 README.md
-rw-r--r--  1 okasakuya  staff  238232  7  9 21:29 README.pdf
-rwxr-xr-x  1 okasakuya  staff   50392  7  9 22:45 mysysmain
-rw-r--r--  1 okasakuya  staff     925  7  9 21:29 mysysmain.c
-rw-r--r--  1 okasakuya  staff    1154  7  9 22:45 mysystem.c
-rw-r--r--  1 okasakuya  staff      90  7  9 21:29 mysystem.h

total 616
-rw-r--r--  1 okasakuya  staff     143  7  9 21:29 Makefile
-rw-r--r--  1 okasakuya  staff    2795  7  9 21:29 README.md
-rw-r--r--  1 okasakuya  staff  238232  7  9 21:29 README.pdf
-rwxr-xr-x  1 okasakuya  staff   50392  7  9 22:45 mysysmain
-rw-r--r--  1 okasakuya  staff     925  7  9 21:29 mysysmain.c
-rw-r--r--  1 okasakuya  staff    1214  7  9 22:47 mysystem.c
-rw-r--r--  1 okasakuya  staff      90  7  9 21:29 mysystem.h
retval = 00000000
system:
total 616
-rw-r--r--  1 okasakuya  staff     143  7  9 21:29 Makefile
-rw-r--r--  1 okasakuya  staff    2795  7  9 21:29 README.md
-rw-r--r--  1 okasakuya  staff  238232  7  9 21:29 README.pdf
-rwxr-xr-x  1 okasakuya  staff   50392  7  9 22:45 mysysmain
-rw-r--r--  1 okasakuya  staff     925  7  9 21:29 mysysmain.c
-rw-r--r--  1 okasakuya  staff    1214  7  9 22:47 mysystem.c
-rw-r--r--  1 okasakuya  staff      90  7  9 21:29 mysystem.h
retval = 00000000

okasakuya@okasakinarinoMacBook-Air kadai10-i21oka % ./mysysmain 
使い方 : ./mysysmain コマンド文字列

*/
