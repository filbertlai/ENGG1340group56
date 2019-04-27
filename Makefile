main.o: main.cpp add.h edit.h delete.h catetory.h budget.h report.h search.h
  g++ -c main.cpp

add.o: add.cpp add.h
  g++ -c add.cpp
  
edit.o: edit.cpp edit.h
  g++ -c edit.cpp

delete.o: delete.cpp delete.h
  g++ -c delete.cpp
  
catetory.o: catetory.cpp catetory.h
  g++ -c catetory.cpp
  
budget.o: budget.cpp budget.h
  g++ -c budget.cpp
  
report.o: report.cpp report.h
  g++ -c report.cpp
  
search.o: search.cpp search.h
  g++ -c search.cpp

interface: main.o budget.o category.o delete.o edit.o report.o search.o add.o
  g++ -c main.o budget.o category.o delete.o edit.o report.o search.o add.o -o interface
  
run:
  ./interface
  
g++ main.cpp budget.cpp category.cpp delete.cpp edit.cpp report.cpp search.cpp add.cpp -o interface

