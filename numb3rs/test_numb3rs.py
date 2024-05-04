from numb3rs import validate


def test_ip():
    assert validate("127.0.0.1") == True


def test_zero():
    assert validate("0.0.0.0") == True


def test_max():
    assert validate("255.255.255.255") == True


def test_first():
    assert validate("512.0.0.0") == False
    assert validate("0.512.0.0") == False


def test_second():
    assert validate("0.0.512.0") == False
    assert validate("0.0.0.512") == False


def test_full():
    assert validate("512.512.512") == False


def test_cat():
    assert validate("cat") == False
