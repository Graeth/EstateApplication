CXX := g++

all: EstateApplication.o mongoose.o
	$(CXX) -o estateApp EstateApplication.o mongoose.o -I.
	
EstateApplication.o: EstateApplication.cxx
	$(CXX) -c EstateApplication.cxx
	
mongoose.o: mongoose.c
	$(CXX) -c mongoose.c


