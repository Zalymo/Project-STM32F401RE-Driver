.syntax unified
.cpu cortex-m4
.fpu vfp

.section .data
nop

.section .text
.global vtable
.global reset_handler
.global yield

.type vtable, %object
vtable:
  .word _estack
  .word reset_handler
.size vtable, .-vtable

/*
.type yield, %function
yield:
  push {lr}

  mov r1, 0xF00
  movt r1, 0xFF
  //mul r1, r0

  delay:
    subs r1, 3
    bne delay

  pop {lr}

  bx lr

.size yield, .-yield
*/
.type reset_handler, %function
reset_handler:
  // Set the stack pointer to the end of the stack.
  nop
  ldr	r0, =_estack
  mov	sp, r0

.size reset_handler, .-reset_handler