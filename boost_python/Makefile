ifeq ($(OS),Windows_NT)
test.pyd: test.cpp
	g++ -shared -fPIC test.cpp -o test.pyd -I /mingw64/include/python3.8 -lboost_python38-mt -lpython3.8

clean:
	$(RM) test.pyd

else
UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
test.so: test.cpp
	g++ -shared -fPIC test.cpp -o test.so -I /usr/include/python3.8 -lboost_python38 -lpython3.8

clean:
	$(RM) test.so

endif
endif