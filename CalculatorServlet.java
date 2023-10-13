import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/calculator")
public class CalculatorServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String name = "Your Name";
        String rollNumber = "123456";
        String className = "10th";
        String department = "Science";

        int num1 = Integer.parseInt(request.getParameter("number1"));
        int num2 = Integer.parseInt(request.getParameter("number2"));

        int add = num1 + num2;
        int subtract = num1 - num2;
        int multiply = num1 * num2;
        int divide = num1 / num2;

        out.println("<html>");
        out.println("<head>");
        out.println("<link rel='stylesheet' type='text/css' href='style.css'>");
        out.println("</head>");
        out.println("<body>");
        out.println("<h1>Arithmetic Operations</h1>");
        out.println("<table>");
        out.println("<tr><td>Number 1: </td><td>" + num1 + "</td></tr>");
        out.println("<tr><td>Number 2: </td><td>" + num2 + "</td></tr>");
        out.println("<tr><td>Addition: </td><td>" + add + "</td></tr>");
        out.println("<tr><td>Subtraction: </td><td>" + subtract + "</td></tr>");
        out.println("<tr><td>Multiplication: </td><td>" + multiply + "</td></tr>");
        out.println("<tr><td>Division: </td><td>" + divide + "</td></tr>");
        out.println("</table>");
        out.println("<h2>Personal Information</h2>");
        out.println("<ul>");
        out.println("<li>Name: " + name + "</li>");
        out.println("<li>Roll Number: " + rollNumber + "</li>");
        out.println("<li>Class: " + className + "</li>");
        out.println("<li>Department: " + department + "</li>");
        out.println("</ul>");
        out.println("</body>");
        out.println("</html>");
    }
}