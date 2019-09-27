#!/bin/bash

find $( pwd ) -type f -printf "File Path: %p | Size:  %s bytes\n"
