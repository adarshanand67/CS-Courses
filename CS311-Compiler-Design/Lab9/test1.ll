; ModuleID = 'test.c'
 source_filename = "test.c"
 target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
 target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
 define dso_local i32 @main() #0 {
%1 = alloca i32 , align 4 
%2 = alloca i32 , align 4 
%3 = alloca i32 , align 4 
store i32 0, i32* %1, align 4
store i32 6, i32* %2, align 4 
store i32 7, i32* %3, align 4 
%4 = load i32, i32* %2, align 4 
%5 = load i32, i32* %3, align 4 
%6 = icmp sgt i32 %4, %5 
br i1 %6, label _, label %7 

7: 
%8 = load i32, i32* %3, align 4 
%9 = load i32, i32* %2, align 4 
%10 = icmp sgt i32 %8, %9 
br i1 %10, label _, label %11 

11: 
%12 = load i32, i32* %2, align 4 
%13 = sub nsw i32 %12, 1 
store i32 %13, i32* %1, align 4 
br label _

ret i32 0 
}
attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

 !llvm.module.flags = !{!0, !1, !2, !3, !4}
 !llvm.ident = !{!5}

 !0 = !{i32 1, !"wchar_size", i32 4}
 !1 = !{i32 7, !"PIC Level", i32 2}
 !2 = !{i32 7, !"PIE Level", i32 2}
 !3 = !{i32 7, !"uwtable", i32 1}
 !4 = !{i32 7, !"frame-pointer", i32 2}
 !5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1"}
