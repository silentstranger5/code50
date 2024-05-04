from jar import Jar
import pytest


def test_init():
    jar = Jar(5)
    assert jar.capacity == 5
    pytest.raises(ValueError, Jar, -1)


def test_str():
    jar = Jar()
    assert str(jar) == ""
    jar.deposit(1)
    assert str(jar) == "🍪"
    jar.deposit(11)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪"


def test_deposit():
    jar = Jar(7)
    jar.deposit(5)
    assert jar.size == 5
    pytest.raises(ValueError, jar.deposit, 5)


def test_withdraw():
    jar = Jar()
    jar.deposit(7)
    assert jar.size == 7
    pytest.raises(ValueError, jar.withdraw, 12)
