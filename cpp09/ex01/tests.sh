#!bin/bash

BIN=RPN

make

if [ $? -eq 0 ]; then
	echo
	echo -e "\e[32m Expressão: 8 9 * 9 - 9 - 9 - 4 - 1 + \e[0m "
	echo -e "\e[32m Resultado esperado: 42 \e[0m"
	echo -e "Resultado: "
	./$BIN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	echo

	echo -e "\e[32m Expressão: 7 7 * 7 - \e[0m"
	echo -e "\e[32m Resultado esperado: 42 \e[0m"
	echo -e "Resultado: "
	./$BIN "7 7 * 7 -"
	echo

	echo -e "\e[32m Expressão: 1 2 * 2 / 2 * 2 4 - + \e[0m"
	echo -e "\e[32m Resultado esperado: 0 \e[0m"
	echo -e "Resultado: "
	./$BIN "1 2 * 2 / 2 * 2 4 - +"
	echo

	echo -e "\e[32m Expressão: (1 + 1) \e[0m"
	echo -e "\e[32m Resultado esperado: Error \e[0m"
	echo -e "Resultado: "
	./$BIN "(1 + 1)"
	echo

	echo -e "\e[32m Expressão: 5 1 2 + 4 * + 3 - \e[0m"
	echo -e "\e[32m Resultado esperado: 14 \e[0m"
	echo -e "Resultado: "
	./$BIN "5 1 2 + 4 * + 3 -"
	echo

	echo -e "\e[32m Expressão: 5 - \e[0m"
	echo -e "\e[32m Resultado esperado: Error \e[0m"
	echo -e "Resultado: "
	./$BIN "5 -"
	echo

		echo -e "\e[32m Expressão: 5 2 - + \e[0m"
	echo -e "\e[32m Resultado esperado: Error \e[0m"
	echo -e "Resultado: "
	./$BIN "5 2 - +"
	echo

		echo -e "\e[32m Expressão: 8 4 * 9 + 4 2 / 6 1 - + * \e[0m"
	echo -e "\e[32m Resultado esperado: 287 \e[0m"
	echo -e "Resultado: "
	./$BIN "8 4 * 9 + 4 2 / 6 1 - + *"
	echo

	echo -e "\e[32m Expressão: 7 8 * 4 0 / \e[0m"
	echo -e "\e[32m Resultado esperado: Error \e[0m"
	echo -e "Resultado: "
	./$BIN "7 8 * 4 0 / 7 + 9 6 + -"
	echo

	make fclean
else
	echo "Compilation error."
fi