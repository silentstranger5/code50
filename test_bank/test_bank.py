from bank import value


def test_hello():
    assert value("hello, Newman") == 0
    assert value("hello, Mr.Smith") == 0


def test_h():
    assert value("hey there!") == 20
    assert value("how's it going?") == 20


def test_none():
    assert value("what's up?") == 100
    assert value("what's going on?") == 100


def test_caps():
    assert value("HELLO, SIR!") == 0
    assert value("HEY, WHAT'S UP?") == 20
    assert value("WHAT'S GOING ON?") == 100
