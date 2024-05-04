from twttr import shorten


def test_vowels():
    assert shorten("eutopia") == "tp"
    assert shorten("eulogia") == "lg"


def test_cap():
    assert shorten("HEY THERE!") == "HY THR!"
    assert shorten("WHAT'S UP?") == "WHT'S P?"


def test_low():
    assert shorten("magnum mysterium") == "mgnm mystrm"
    assert shorten("verum sine mendacio") == "vrm sn mndc"


def test_numbers():
    assert (
        shorten("pi number approximately equals 3.14159265359")
        == "p nmbr pprxmtly qls 3.14159265359"
    )
    assert (
        shorten("one of the most widely usen number in math is e ~ 2.71828182846")
        == "n f th mst wdly sn nmbr n mth s  ~ 2.71828182846"
    )


def test_punct():
    shorten(
        "then please, answer, how had this happened?"
    ) == "thn pls, answr, hw hd ths hppnd?"
    shorten(
        "here, and there, and over here, you can see them everywhere!"
    ) == "hr, nd thr, nd vr hr, y cn s thm vrywhr!"
