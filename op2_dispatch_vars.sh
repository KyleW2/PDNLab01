#!/usr/bin/env bash

######################################
# DO NOT CHANGE THIS FOLLOWING LINE: #
OP2_BASELINE_FILE="baseline_op_02.c" #
######################################

############################################
# HOWEVER, CHANGE THESE LINES:             #
# Replace the filenames with your variants #
############################################
OP2_SUBMISSION_VAR01_FILE="lightning_mcqueen.c" # <-- CHANGE ME!
OP2_SUBMISSION_VAR02_FILE="baseline_op_02.c" # <-- CHANGE ME!
OP2_SUBMISSION_VAR03_FILE="baseline_op_02.c" # <-- CHANGE ME!

######################################################
# You can even change the compiler flags if you want #
######################################################
# CFLAGS="-std=c99 -O2"
CFLAGS="-pthread -std=c99 -O2 -mavx2 -mfma -lpthread"

