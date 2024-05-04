import pytest
from working import convert


def test_full():
    assert convert("9:00 AM to 5:00 PM") == "09:00 to 17:00"


def test_short_right():
    assert convert("9:30 AM to 5 PM") == "09:30 to 17:00"


def test_short_left():
    assert convert("9 AM to 5:30 PM") == "09:00 to 17:30"


def test_short_full():
    assert convert("9 AM to 5 PM") == "09:00 to 17:00"


def test_order():
    assert convert("10 PM to 6 AM") == "22:00 to 06:00"


def test_hours():
    pytest.raises(ValueError, convert, "13:00 AM to 15:00 PM")


def test_minutes():
    pytest.raises(ValueError, convert, "9:60 AM to 5:60 PM")


def test_format_short():
    pytest.raises(ValueError, convert, "9 AM - 5 PM")


def test_format_full():
    pytest.raises(ValueError, convert, "9:00 AM - 5:00 PM")
