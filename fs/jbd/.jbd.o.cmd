cmd_fs/jbd/jbd.o := /mnt/disk2/Dev/UG802/kernel/toolchains/arm-eabi-linaro-4.6.2/bin/arm-eabi-ld.bfd -EL    -r -o fs/jbd/jbd.o fs/jbd/transaction.o fs/jbd/commit.o fs/jbd/recovery.o fs/jbd/checkpoint.o fs/jbd/revoke.o fs/jbd/journal.o 