import pytest
from seasons import convert


def test_one_year():
    assert (
        convert("2022-06-12")
        == "Five hundred twenty-five thousand, six hundred minutes"
    )


def test_two_years():
    assert (
        convert("2021-06-12") == "One million, fifty-one thousand, two hundred minutes"
    )


def test_invalid_format():
    pytest.raises(SystemExit, convert, "January 1, 1999")


def test_invalid_value():
    pytest.raises(SystemExit, convert, "1970-30-12")
