#!/usr/bin/ruby

require 'builder'

xml = Builder::XmlMarkup.new :indent=>2

xml.instruct! :xml, :version=>"1.0", :encoding=>"UTF-8"
xml.template(class: "GCardsGreeterWindow", parent: "GtkApplicationWindow") do |t|
  t.property("1280", name: "default-width")
  t.property("800", name: "default-height")
  t.child(type: "titlebar") do |ch|
    ch.object(class: "GtkHeaderBar", id: "header_bar") do |obj|
      obj.property("true", name: "visible")
    end
  end
end

File.write('../src/resources/ui/gc-greeter-window.ui', xml.target!)
