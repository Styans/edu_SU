package handlers

import (
	"net/http"
	"web_site/internal/render"
)

func (h *Handler) contacts(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path != "/contacts" {
		http.Error(w, "Not found", http.StatusNotFound)
		return
	}
	if r.Method != "GET" {
		http.Error(w, "method not GET", http.StatusInternalServerError)
		return
	}
	h.templates.Render(w, r, "contacts.page.html", &render.PageData{
		Topic: "contacts",
	})
}
