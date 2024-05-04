from fpdf import FPDF


def main():
    convert(input("Name: "))


def convert(s):
    pdf = FPDF()
    pdf.set_auto_page_break(False)
    pdf.add_page()
    pdf.set_font("Helvetica", size=48)
    pdf.cell(
        0,
        40,
        "CS50 Shirtificate",
        new_x="LMARGIN",
        new_y="NEXT",
        align="C",
    )
    pdf.ln(20)
    pdf.image("shirtificate.png", x="C", w=pdf.epw)
    pdf.set_font("Helvetica", size=24)
    pdf.set_text_color(255, 255, 255)
    pdf.cell(0, -240, f"{s} took CS50", align="C")
    pdf.output("shirtificate.pdf")


if __name__ == "__main__":
    main()
