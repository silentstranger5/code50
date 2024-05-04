from fuel import convert, gauge
import pytest


def test_nan():
    pytest.raises(ValueError, convert, "cat/dog")
    pytest.raises(ValueError, convert, "5/4")


def test_zero():
    pytest.raises(ZeroDivisionError, convert, "1/0")
    pytest.raises(ZeroDivisionError, convert, "2/0")


def test_convert():
    assert convert("1/2") == 50
    assert convert("3/4") == 75


def test_e():
    assert gauge(0) == "E"
    assert gauge(1) == "E"


def test_f():
    assert gauge(99) == "F"
    assert gauge(100) == "F"


def test_gauge():
    assert gauge(50) == "50%"
    assert gauge(75) == "75%"
