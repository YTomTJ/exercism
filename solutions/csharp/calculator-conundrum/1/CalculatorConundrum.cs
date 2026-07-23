public static class SimpleCalculator
{
    public static string Calculate(int operand1, int operand2, string? operation)
    {
        if (operation is null) {
            throw new ArgumentNullException();
        }
        if (string.IsNullOrEmpty(operation)) {
            throw new ArgumentException();
        }
        if (operation == "+") {
            return $"{operand1} + {operand2} = {operand1 + operand2}";
        }
        if (operation == "*") {
            return $"{operand1} * {operand2} = {operand1 * operand2}";
        }
        if (operation == "/") {
            if (operand2 == 0) {
                return "Division by zero is not allowed.";
            }
            return $"{operand1} / {operand2} = {operand1 / operand2}";
        }
        throw new ArgumentOutOfRangeException();
    }
}
