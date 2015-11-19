#!/usr/bin/ruby

require 'builder'

xml = Builder::XmlMarkup.new :indent=>2

xml.instruct! :xml, :version=>"1.0", :encoding=>"UTF-8"
xml.interface do |i|
  i.template(class: "GCardsSessionWindow", parent: "GtkApplicationWindow") do |t|
    t.child(type: "titlebar") do |ch|
      ch.object(class: "GtkHeaderBar", id: "header_bar") do |obj|
        obj.property("true", name: "visible")
        obj.property("true", name: "show-close-button")
      end
    end
  end
end
File.write('../src/resources/ui/gc-session-window.ui', xml.target!)
