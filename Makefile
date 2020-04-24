
TARGET = password_cracker

OFILES = password_cracker.o

CXX = g++

CFLAGS = -g -Wall -std=c++17

LDFLAGS =

$(TARGET):	$(OFILES)
		$(CXX) $(OFILES) $(LDFLAGS) -o $@

clean:
	rm -f *~ $(OFILES) $(TARGET)

password_cracker.o:	password_cracker.cc

TARGET:		password_cracker.o password_cracker.cc
