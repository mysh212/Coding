@findstr /V #include^<bits/stdc++.h^> %road% > cbb.cpp
@echo #include^<bits/stdc++.h^> > tmp.o
@"g++.exe" -E cbb.cpp -I"C:\Users\user\Coding\library" >> tmp.o&&type tmp.o|clip&&echo  ^>Finished.
@del tmp.o