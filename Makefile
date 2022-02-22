###############################################################################
#         University of Hawaii, College of Engineering
# @brief  Lab 04c - Countdown - EE 205 - Spr 2022
#
# @file    Makefile
# @version 1.0
#
# @author Brayden Suzuki <braydens@hawaii.edu>
# @date   Feb 21 2022
#
# @see     https://www.gnu.org/software/make/manual/make.html
###############################################################################

TARGET = countdown


all:  $(TARGET)


CC     = gcc
CFLAGS = -Wall -Wextra $(DEBUG_FLAGS)

debug: DEBUG_FLAGS = -g -DDEBUG
debug: clean $(TARGET)


countdown.o: countdown.c
	$(CC) $(CFLAGS) -c countdown.c


countdown: countdown.o
	$(CC) $(CFLAGS) -o $(TARGET) countdown.o


test: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(TARGET) *.o
