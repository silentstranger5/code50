from plates import is_valid


def test_start():
    assert is_valid("50") == False
    assert is_valid("A4") == False


def test_length():
    assert is_valid("P") == False
    assert is_valid("OUTATIME") == False


def test_numbers():
    assert is_valid("CS50P") == False
    assert is_valid("CS05") == False


def test_sign():
    assert is_valid("PI3.14") == False
    assert is_valid("BYE!") == False

