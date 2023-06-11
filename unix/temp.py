two_bits = "169.33"
for idx in range(1, 31):
    first_three_bits = f"{two_bits}.{idx*8}"
    second_three_bits = f"{two_bits}.{idx*8 + 7}"
    with open("lab15.md", "a") as file:
        file.write(
            f"| {first_three_bits}.0 | {first_three_bits}.1 | {second_three_bits}.254 | {second_three_bits}.255 |\n"
        )
