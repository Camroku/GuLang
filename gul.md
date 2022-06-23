# GuLang Documentation
Things you need know about before reading this:
* Registers: There are 10 registers (`0`-`9`) in GuLang which you can put integer or character values in.
* Current Register: The selected register.
* Address: Position of an instruction in the file.
* `a`, `b`, and other characters are arguments that should be with registers, check the examples.
* When the program starts, the current register is 0 by default.

Some aliases to make this table shorter:
* `crv` = current register's value
* int = integer
* char = character
* reg = register

| Instruction | Description | Example | Example Description |
| ----------- | ----------- | ------- | ------------------- |
| `0` - `9` | Set `crv` to that number. | `3` | Set `crv` to 3. |
| `` `a `` | Set current reg to `a`. | `` `4 `` | Set current reg to 4. |
| `+ab` | Set `crv` to reg `a`'s value + reg `b`'s value. | `+12` | Set `crv` to reg 1's value + reg 2's value. |
| `-ab` | Set `crv` to reg `a`'s value - reg `b`'s value. | `-12` | Set `crv` to reg 1's value - reg 2's value. |
| `*ab` | Set `crv` to reg `a`'s value * reg `b`'s value. | `*12` | Set `crv` to reg 1's value * reg 2's value. |
| `/ab` | Set `crv` to reg `a`'s value / reg `b`'s value. | `/12` | Set `crv` to reg 1's value / reg 2's value. |
| `%ab` | Set `crv` to reg `a`'s value % reg `b`'s value. | `%12` | Set `crv` to reg 1's value % reg 2's value. |
| `"` | Print `crv` as a char. | `` `15`22`0*12" `` | Set reg 1 to 5, set reg 2 to 2, set reg 0 to reg 1 * reg 2, print `crv` as a char (prints a newline) |
| `'` | Print `crv` as an int. | `5'` | Set `crv` to 5, print it as an int. |
| `:a` | Set `crv` to `a`'s ASCII value. | `:G"` | Set `crv` to `G`'s ASCII value (71), print it as an char. |
| `#` | Set `crv` to int input. | `#"` | Get int input and print it as a char. |
| `@` | Set `crv` to char input. | `@'` | Get char input and print it as an int. |
| `=` | Set `crv` to next instruction's address. | `='` | Get next instruction's address and print it as an int. (In a single file without any other code, this'll be `1`) |
| `^` | Set current address to `crv`. | `=^` | A loop that continously sets current address to 1. |
| `!` | Exit with code 0. | `!` | Exit with code 0. |
| `\|ab` | If `crv` is 0 jump to code at reg `a`'s value, else jump to code at `b`. Skip if the variable is empty. | An example for this would be too long, check the `test.gul` file in `src` directory | None |
| `[` | Set `crv` to next instruction's address and skip until you find `]` | `` [`1'!]`15`0^ `` | Set `crv` to 0, skip until `]`, set current reg to 1, set `crv` to 5, set current reg to 0, jump to address 1, set current reg to 1, print `crv` as int, exit. |
| `]` | Skipped | `]` | Nothing |
| any space | Skipped | None | Nothing |